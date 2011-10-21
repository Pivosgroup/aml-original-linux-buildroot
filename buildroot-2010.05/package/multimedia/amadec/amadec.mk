#############################################################
#
# amadec
#
#############################################################
AMADEC_VERSION:=0.9.9
AMADEC_DIR=$(BUILD_DIR)/amadec
AMADEC_SOURCE=src
AMADEC_SITE=.

$(AMADEC_DIR)/.unpacked:


amadecd-unpack:
	mkdir -p $(AMADEC_DIR)
	cp -arf ./package/multimedia/amadec/src/* $(AMADEC_DIR)
	touch $(AMADEC_DIR)/.unpacked

$(AMADEC_DIR)/amadec: $(AMADEC_DIR)/.unpacked
	$(MAKE) CC=$(TARGET_CC) -C $(AMADEC_DIR)
	touch -c $(AMADEC_DIR)/amadec

$(TARGET_DIR)/bin/amadec: $(AMADEC_DIR)/amadec
	install -m 755 $(AMADEC_DIR)/amadecc $(TARGET_DIR)/bin
	install -m 755 $(AMADEC_DIR)/amadecd $(TARGET_DIR)/bin
	touch -c $(TARGET_DIR)/bin/amadecc
	touch -c $(TARGET_DIR)/bin/amadecd

amadec:amadecd-unpack $(TARGET_DIR)/bin/amadec

amadec-source: $(DL_DIR)/$(AMADEC_SOURCE)

amadec-clean:
	-$(MAKE) -C $(AMADEC_DIR) clean

amadec-dirclean:
	rm -rf $(AMADEC_DIR)

#############################################################
#
# Toplevel Makefile options
#
#############################################################
ifeq ($(BR2_PACKAGE_AMADEC),y)
TARGETS+=amadec
endif
