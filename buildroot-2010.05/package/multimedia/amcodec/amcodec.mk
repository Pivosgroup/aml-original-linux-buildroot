#############################################################
#
# amcodec
#
#############################################################
AMCODEC_VERSION:=0.9.9
AMCODEC_DIR=$(BUILD_DIR)/amcodec
AMCODEC_SOURCE=src
AMCODEC_SITE=.

export INC_DIR=$(STAGING_DIR)/usr

$(AMCODEC_DIR)/.unpacked:amcodec-unpacked

amcodec-unpacked:
	-rm -rf $(AMCODEC_DIR)
	mkdir -p $(AMCODEC_DIR)
	cp -arf ./package/multimedia/amcodec/src/* $(AMCODEC_DIR)
	touch $(AMCODEC_DIR)/.unpacked

$(AMCODEC_DIR)/.installed:$(AMCODEC_DIR)/amcodec

$(AMCODEC_DIR)/amcodec: $(AMCODEC_DIR)/.unpacked
	$(MAKE) CC=$(TARGET_CC) -C $(AMCODEC_DIR) install
	touch $(AMCODEC_DIR)/.installed

amcodec:$(AMCODEC_DIR)/.installed

amcodec-source: $(DL_DIR)/$(AMCODEC_SOURCE)

amcodec-clean:
	-$(MAKE) -C $(AMCODEC_DIR) clean

amcodec-dirclean:
	rm -rf $(AMCODEC_DIR)

#############################################################
#
# Toplevel Makefile options
#
#############################################################
ifeq ($(BR2_PACKAGE_AMCODEC),y)
TARGETS+=amcodec
endif
