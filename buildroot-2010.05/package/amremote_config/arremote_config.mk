#############################################################
#
# amremote_config
#
#############################################################
LIBBTTV_VERSION:=1.0.0
AMREMOTE_CONFIG=$(BUILD_DIR)/amremote_config-$(LIBBTTV_VERSION)
LIBBTTV_SOURCE=src
LIBBTTV_SITE=.

$(AMREMOTE_CONFIG)/.unpacked:
	mkdir -p $(AMREMOTE_CONFIG)
	cp -arf ./package/amremote_config/src/* $(AMREMOTE_CONFIG)
	touch $(AMREMOTE_CONFIG)/.unpacked

$(AMREMOTE_CONFIG)/.configured: $(AMREMOTE_CONFIG)/.unpacked
	(cd $(AMREMOTE_CONFIG); rm -rf config.cache; \
	    $(TARGET_CONFIGURE_OPTS) \
	    $(TARGET_CONFIGURE_ARGS) \
	    LDFLAGS="-L$(TARGET_DIR)/usr/lib" \
	)
	touch $(AMREMOTE_CONFIG)/.configured

$(AMREMOTE_CONFIG)/amremote_config: $(AMREMOTE_CONFIG)/.configured
	$(MAKE) CC=$(TARGET_CC) -C $(AMREMOTE_CONFIG) 
	touch -c $(AMREMOTE_CONFIG)/amremote_config

$(TARGET_DIR)/lib/amremote_config: $(AMREMOTE_CONFIG)/amremote_config
	install -m 755 $(AMREMOTE_CONFIG)/amremote_config  $(TARGET_DIR)/usr/bin/amremote_config

amremote_config: $(TARGET_DIR)/lib/amremote_config

amremote_config-source: $(DL_DIR)/$(LIBBTTV_SOURCE)

amremote_config-clean:
	-$(MAKE) -C $(AMREMOTE_CONFIG) clean

amremote_config-dirclean:
	rm -rf $(AMREMOTE_CONFIG)


#############################################################
#
# Toplevel Makefile options
#
#############################################################
ifeq ($(BR2_PACKAGE_LIBBTTV),y)
TARGETS+=amremote_config
endif
