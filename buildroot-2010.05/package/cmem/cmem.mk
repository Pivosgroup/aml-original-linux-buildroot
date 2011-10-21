#############################################################
#
#cmem 
#
#############################################################
CMEM_VERSION:=0.9.9
CMEM_DIR=$(BUILD_DIR)/cmem
CMEM_SOURCE=${CMEM-D}
CMEM_SITE=.

export PREFIX=$(TARGET_DIR)/usr
export STAGING=$(STAGING_DIR)/usr

CMEM_TARGET_BINARY=$(PREFIX)/usr/lib/libcmem.a


$(CMEM_DIR)/.unpacked:
	-rm -rf $(CMEM_DIR)
	mkdir -p $(CMEM_DIR)
	cp -arf ./package/cmem/src/* $(CMEM_DIR)
	sh ./package/cmem/get_svn_info.sh $(CMEM_DIR)/version.h
	touch $@

$(CMEM_TARGET_BINARY): $(CMEM_DIR)/.unpacked
	$(MAKE) CC=$(TARGET_CC) -C $(CMEM_DIR)

libcmem.a: $(CMEM_TARGET_BINARY)

cmem-clean:
	-$(MAKE) -C $(CMEM_DIR) clean

cmem-dirclean:
	rm -rf $(CMEM_DIR)

#############################################################
#
# Toplevel Makefile options
#
#############################################################
ifeq ($(BR2_PACKAGE_CMEM),y)
TARGETS+=libcmem.a
endif
