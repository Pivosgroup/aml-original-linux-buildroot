Building the rootfs is complicated because the tarball
that amlogic supplies is defective but we can use their
binary release instead. But we still need to build the
rootfs part as we need the include/libs to be able to
build xbmc from scratch.

The bootable rootfs is assumed to be going to /opt/aml-root. Also the cross toolchain is assumed to be at /opt/arm-2010q1 with a symlink to /opt/CodeSourcery/Sourcery_G++_Lite.

Fetch and install binary rootfs:
 wget http://openlinux.amlogic.com/download/linux/ARM/filesystem/arm-rootfs-2011-08-31-14.00--svn2033.tar.gz
 tar xf rootfs-2011-08-31-14.00--svn2033.tar.gz
 sudo mkdir -p /opt/aml-rootfs
 sudo cp -r arm-rootfs-2011-08-31-14.00--svn2033/* /opt/aml-rootfs
 sudo mkdir -p /opt/aml-rootfs/opt/xbmc-aml

Build rootfs for includes/libs:
 export PATH=/opt/arm-2010q1/bin:$PATH
 cp buildroot.config buildroot-2010.05/.config
 cp busybox.config buildroot-2010.05/busybox.config
 cp buildroot-2010.05
 make
 got to lunch, it will take a long time to fetch and build

Normally, one would use the built image to populate the rootfs but that is
currently broke :(
 sudo tar -C /opt/aml-rootfs -xf output/images/rootfs.tar.gz
