#############################################################
#
#amljpeg
#
#############################################################
AMLJPEG_VERSION:=0.9.9
AMLJPEG_DIR=$(BUILD_DIR)/amljpeg
AMLJPEG_SOURCE=${AMLJPEG-D}
AMLJPEG_SITE=.

export PREFIX=$(TARGET_DIR)/usr
export STAGING=$(STAGING_DIR)/usr

AMLJPEG_TARGET_BINARY=$(PREFIX)/usr/lib/libamljpeg.a


$(AMLJPEG_DIR)/.unpacked:
	-rm -rf $(AMLJPEG_DIR)
	mkdir -p $(AMLJPEG_DIR)
	cp -arf ./package/amljpeg/src/* $(AMLJPEG_DIR)
#	sh ./package/amljpeg/get_svn_info.sh $(AMLJPEG_DIR)/version.h
	touch $@

$(AMLJPEG_TARGET_BINARY): $(AMLJPEG_DIR)/.unpacked
	$(MAKE) CC=$(TARGET_CC) -C $(AMLJPEG_DIR)

libamljpeg.a: $(AMLJPEG_TARGET_BINARY)

amljpeg-clean:
	-$(MAKE) -C $(AMLJPEG_DIR) clean

amljpeg-dirclean:
	rm -rf $(AMLJPEG_DIR)

#############################################################
#
# Toplevel Makefile options
#
#############################################################
ifeq ($(BR2_PACKAGE_AMLJPEG),y)
TARGETS+=libamljpeg.a
endif
