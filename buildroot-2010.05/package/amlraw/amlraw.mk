#############################################################
#
#amlraw
#
#############################################################
AMLRAW_VERSION:=0.9.9
AMLRAW_DIR=$(BUILD_DIR)/amlraw
AMLRAW_SOURCE=${AMLRAW-D}
AMLRAW_SITE=.

export PREFIX=$(TARGET_DIR)/usr
export STAGING=$(STAGING_DIR)/usr

AMLRAW_TARGET_BINARY=$(PREFIX)/usr/lib/libamlraw.a


$(AMLRAW_DIR)/.unpacked:
	-rm -rf $(AMLRAW_DIR)
	mkdir -p $(AMLRAW_DIR)
	cp -arf ./package/amlraw/src/* $(AMLRAW_DIR)
#	sh ./package/amlraw/get_svn_info.sh $(AMLRAW_DIR)/version.h
	touch $@

$(AMLRAW_TARGET_BINARY): $(AMLRAW_DIR)/.unpacked
	$(MAKE) CC=$(TARGET_CC) -C $(AMLRAW_DIR)

libamlraw.a: $(AMLRAW_TARGET_BINARY)

amlraw-clean:
	-$(MAKE) -C $(AMLRAW_DIR) clean

amlraw-dirclean:
	rm -rf $(AMLRAW_DIR)

#############################################################
#
# Toplevel Makefile options
#
#############################################################
ifeq ($(BR2_PACKAGE_AMLRAW),y)
TARGETS+=libamlraw.a
endif
