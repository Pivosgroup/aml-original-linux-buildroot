#################################################
#                                               #
#              IF_MANAGERģ��˵��               #
#                Version 1.1.0                  #
#                                               #
#################################################

1. ׼������:
   1. ��̫��:�����������
   
   2. wifi:�ڱ���kernelʱ, ִ��make k.menuconfig, ������������:
               ��Networking-->Wireless��, ȷ��Generic IEEE 802.11 Networking Stack(������)����ѡ��
               ��Device drivers-->Nerwork device support-->Wireless LAN��, ȷ��ZyDAS ZD1211/ZD1211B USB-wireless support��ѡΪM
               ִ��make k.modules�������ڱ���Ŀ¼�µ�rootfs/lib/modules/�п���zd1211rw.ko(��Ϊ���ǰ���Ŀǰ֧�ֵ�һ��wifi dongle������)
               ִ��make p.RTL819X_Linux2.6_Driver.all�������ڱ���Ŀ¼�µ�rootfs/lib/modules/�п���8712u.ko����Ϊ����֧�ֵ���һ��wifi dongle��������
               ��������ko�ļ��ŵ���Ŀʹ�õ�rootfs�У�����ʹ��insmod���̬����        
               �ڱ���packageʱ, ִ��make p.menuconfig, ������������:
               ��Network Utils Packages Configure��, ȷ��wpa_supplicant_wps_patch support��Wrieless tools 29��ѡ��
               ��Basic Library Configure��, ȷ��openssl-0.9.8 support��ѡ��
               
   3. pppoe:�ڱ���busyboxʱ, ִ��make b.menuconfig, ������������: 
           ��coreutils��, ȷ��basename, tty, uname���ѡ��
           �뽫Դ����е�src/scripts/ppp�ļ��з�����Ŀʹ�õ�rootfs/etc/��
           �뽫Դ����е�src/bin/pppd, pppoe, pppoe-connect, pppoe-init, pppoe-relay, pppoe-server, pppoe-setup, pppoe-sniff, pppoe-start, pppoe-status, pppoe-stop������Ŀʹ�õ�rootfs/bin/��

2. ����˵��:      
   1. ִ��make p.menuconfig�ȿ�����Network Utils Packages Configure���ҵ�if_manager��ѡ�ѡ�м��ɾ�make p����rootfs��
      Ҳ�����ֶ����룬ִ��make p.if_manager-1.1.0.all, ���ɽ�if_managerģ�����rootfs��
   2. ������ɺ�, ������rootfs/lib/���ҵ���ؿ�, ��rootfs/include/ifm/���ҵ�ͷ�ļ�ifm_def.h��if_manager.h����trunk/build/packages/if_manager-1.1.0/test/���ҵ����Գ���ifm_test

3. ʹ��˵��:
   1. Ϊ˫ϵͳ�л���ʹ�ô�ģ�飬�����ͷ�ļ�ifm_def.h, �˽ӿ��ļ��ṩ��һ������setNetwork(), ����һ������, ��ʾ�������, ���еķ���ֵ���ڴ�ͷ�ļ����Ժ����ʽ��ʾ, ���ڲ鿴ʧ��ԭ��.
   network_setting.c��, ��һ���꿪��(USE_NAND), Ĭ�Ϲر�, �˺��ʾ�Ƿ���Ҫ���õ�����Ҫ��nand��ȡ, ����˺걻����, ����Ҫ�����nand��ȡģ��֧��, ��Ҫ���õ����ݻ��nand������; ������setNetwork()���Ѿ�д���˼����������,ʹ����Ҳ���Լ����ո�ʽ�����������. ��ʽ����ʱ, �˺��豻����, ͬʱ������nand��ȡģ��.
   
   2. ��ʹ�ù���ģ��, �����ͷ�ļ�if_manager.h, �����ʹ�õ�API��μ�if_manager.h. һЩ����ֵͬ����ifm_def.h(��ͷ�ļ��ѱ�if_manager.h������ʹ��ʱ�ɲ��ذ������ļ�)�в�����Ӧ�ĳ���ԭ��ĺ궨��ֵ. ʹ��ʱ��ο�Դ����е�src/test/ifm_test.c��ʵ�֣�������while(1)֮ǰ�ĵ���˳�򡣺����᲻������, Ϊif_manager.h�����µĽӿ�.
   
   3. debug��ӡ: ��ifm_def.h�д�//#define DEBUG_PRINT, ���ɴ򿪴�ӡ.
   
4. ����˵����
   1. if_manager:
         ʵ����:��̫��, wifi�Ķ�̬�;�̬����
                AP�б�������ͽ����ȡ
                pppoe�����ú�����, �Ͽ�����
                ��ѯĳ����ӿ��Ƿ��Ѿ�׼���ã�UP״̬��
                ����ĳ����ӿڵ������͹ر�
                ��ѯĳ����ӿڵ���ϸ��Ϣ
                ��ѯ���������״̬
                ˫ϵͳ�����н�AVOS���������д��linux
                ���û����ĵ�ĳ�ӿ�״̬�����仯��ʱ��ͨ���û�ע��Ļص�����֪ͨ�û�
   2. ifm_test:
         ʵ����:��ʼ��if_manager, ע�����״̬�ı�Ļص�����, ����daemon����(ʹ��ʱ���˳���ܴ�)
                ��ѯ��̫��, wifi, pppoe������״̬
                ����AP, ��ӡAP�������, ����AP: AML_BJ
                ���ѻ��IP��ַ�����ڵ�ip��Ϣ��ӡ����
                                
        
