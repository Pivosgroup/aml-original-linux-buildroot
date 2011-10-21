#############################################################
#
# ampicplayer
#
#############################################################
AMPICPLAYER_VERSION:=1.0b
AMPICPLAYER_DIR:=$(BUILD_DIR)/ampicplayer
AMPICPLAYER_CAT:=$(ZCAT)
AMPICPLAYER_BINARY:=ampicplayer
AMPICPLAYER_TARGET_BINARY:=usr/bin/$(AMPICPLAYER_BINARY)

$(AMPICPLAYER_DIR)/.unpacked:
	cp -rap package/ampicplayer/ampicplayer $(BUILD_DIR)
	touch $@

$(AMPICPLAYER_DIR)/.configured: $(AMPICPLAYER_DIR)/.unpacked
	(cd $(AMPICPLAYER_DIR); -rm -f config.cache; \
		CC="$(HOSTCC)" \
		./configure --enable-jpeg --enable-amljpeg --enable-png  \
		--prefix=/usr --disable-gles \
	)
	touch $@

$(AMPICPLAYER_DIR)/$(AMPICPLAYER_BINARY): $(AMPICPLAYER_DIR)/.configured
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(AMPICPLAYER_DIR)

$(TARGET_DIR)/$(AMPICPLAYER_TARGET_BINARY): $(AMPICPLAYER_DIR)/$(AMPICPLAYER_BINARY)
	install -D $(AMPICPLAYER_DIR)/player/$(AMPICPLAYER_BINARY) $(TARGET_DIR)/$(AMPICPLAYER_TARGET_BINARY)
	cp $(AMPICPLAYER_DIR)/pic_core/libampic.a $(STAGING_DIR)/usr/lib
	cp $(AMPICPLAYER_DIR)/include/*.h $(STAGING_DIR)/usr/include

ampicplayer: libpng jpeg libungif $(TARGET_DIR)/$(AMPICPLAYER_TARGET_BINARY)

ampicplayer-clean:
	rm -f $(TARGET_DIR)/$(AMPICPLAYER_TARGET_BINARY)
	-$(MAKE) -C $(AMPICPLAYER_DIR) clean

ampicplayer-dirclean:
	rm -rf $(AMPICPLAYER_DIR)
#############################################################
#
# Toplevel Makefile options
#
#############################################################
ifeq ($(BR2_PACKAGE_AMPICPLAYER),y)
TARGETS+=ampicplayer
endif
