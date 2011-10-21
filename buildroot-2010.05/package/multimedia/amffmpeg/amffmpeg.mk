#############################################################
#
# amffmpeg
#
#############################################################
AMFFMPEG_VERSION:=0.9.9
AMFFMPEG_DIR=$(BUILD_DIR)/amffmpeg
AMFFMPEG_SOURCE=src
AMFFMPEG_SITE=.

PREFIX=$(TARGET_DIR)
export LD_LIBRARY_PATH=$(PREFIX)/usr/lib
export C_INCLUDE_PATH=$(STAGING_DIR)/usr/include

CONFIG_FLAGS= --prefix=${PREFIX} --incdir=$(STAGING_DIR)/usr/include --disable-static --enable-shared --disable-ffplay --disable-ffserver --disable-doc \
    --disable-mpegaudio-hp --disable-encoders --disable-decoder=h264 --disable-muxers --disable-filters --enable-cross-compile \
    --cross-prefix=arm-none-linux-gnueabi- --extra-ldflags=-L${PREFIX}/lib --arch=arm --disable-altivec --disable-amd3dnow \
    --disable-amd3dnowext --disable-mmx --disable-mmx2 --disable-sse --disable-ssse3 --disable-armv5te --disable-armv6 \
    --disable-armv6t2 --disable-armvfp --disable-iwmmxt --disable-mmi --disable-vis --disable-yasm --enable-pic --enable-zlib


ifdef DEBUG
CONFIG_FLAGS+=    --enable-debug --disable-stripping
endif  

$(AMFFMPEG_DIR)/.unpacked:amffmpeg-unpacked

amffmpeg-unpacked:
	mkdir -p $(AMFFMPEG_DIR)
	touch $(AMFFMPEG_DIR)/.unpacked

$(AMFFMPEG_DIR)/.configured: $(AMFFMPEG_DIR)/.unpacked
	cd $(AMFFMPEG_DIR) && $(TOPDIR)/package/multimedia/amffmpeg/src/configure ${CONFIG_FLAGS} 
	touch $(AMFFMPEG_DIR)/.configured

$(AMFFMPEG_DIR)/.installed:$(AMFFMPEG_DIR)/ffmpeg

$(AMFFMPEG_DIR)/ffmpeg: $(AMFFMPEG_DIR)/.configured
	$(MAKE) CC=$(TARGET_CC) -C $(AMFFMPEG_DIR) install
	touch $(AMFFMPEG_DIR)/.installed

amffmpeg:$(AMFFMPEG_DIR)/.installed

amffmpeg-source: $(DL_DIR)/$(AMFFMPEG_SOURCE)

amffmpeg-clean:
	-$(MAKE) -C $(AMFFMPEG_DIR) clean

amffmpeg-dirclean:
	rm -rf $(AMFFMPEG_DIR)

#############################################################
#
# Toplevel Makefile options
#
#############################################################

ifeq ($(BR2_PACKAGE_AMFFMPEG),y)
TARGETS+=amffmpeg
endif
