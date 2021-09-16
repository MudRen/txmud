// workroom.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���õĹ�����");
        set("long",
"������ǲ��õĹ����ҡ���ѧϰ֮�࣬���û������������\n"
"�ң���������ǰ��˼��д���������ϰ���һ�ݡ�������˵������\n"
"ǽ������һ�����µĵ�ͼ��һ�������"+ HIY"׷ �� �� ��"NOR +"����\n"
        );

        set("no_clean_up", 1);

        set("exits",([
        "kaz" : __DIR__"d/kanganzhai/gate",
        "snake" : __DIR__"d/path1/tch_ft17",
        "dt" : __DIR__"d/gaibang/dt_fenduo",
        "ca" : __DIR__"d/gaibang/ca_fenduo",
        "out" : "/d/changan/jiulou",
        "up" : __DIR__"upstairs",
        "ft" : __DIR__"d/gaibang/ft_fenduo",
        "kf" : __DIR__"d/gaibang/kf_fenduo",
        ]));

        set("objects", ([
        __DIR__"home/desk" : 1,
        ]));

        set("item_desc", ([
        "instruction" : 
HIY "                         �� �� �� ˵ ��

" NOR,
        "map" : 
HIW "                          �� �� �� ͼ

    ������-cac     �����-ftc     ��Ҵ�-zjc     ���µ�-myd 
    ������-wmd     ����-fyg     ����կ-pyz     ��ͬ��-dtf 
    �ڷ�կ-hfz     ��ˮ��-tsz     ��ɽ��-hsp     ������-hyc 
    ��ϼ��-zxg     �봨��-wcz     ������-sls     ���⸮-kff
    ���ɽ-mfs     ����կ-kaz     ţͷɽ-nts     ���ݳ�-hzc
    �ɶ�  -cd      ����  -tm      ѩͤ��-xtz     ̤ѩׯ-txz

    ����qu cac�Ϳ���ȥ�������ǣ�����ĵط�Ҳ�������Ƶص��
" NOR,

]));

        set("valid_startroom", 1);

        setup();

}

void init()
{
        add_action("do_save","save");
        add_action("do_qu","qu");
}
 
int do_save(string arg)
{
        object me = this_player();

        if(me && geteuid(me) == "tag")
                return 0;
        else
        {
                tell_object(me, "�����ǲ��õĹ����ң��㲻���趨����Ϊ��ʼ�ص㡣\n");
                return 1;
        }
}

int do_qu(string arg)
{
         object me;
         me = this_player();
         if( !arg )
         return notify_fail("���Ŀ��ص���ܵ��\n");

        if ( arg =="cac")
        {
                me->move("/d/changan/jiulou");
                return 1;
        }
 
        if ( arg =="ftc")
        {
                me->move("/d/fengtian/cross");
                return 1;       
         }

        if ( arg =="zjc")
        {
                me->move("/d/zuojiacun/lu18");
                return 1; 
        }

        if ( arg =="myd")
        {
                me->move("/d/jinghai/moon7");
                return 1;       
        }

        if ( arg =="wmd")
        {
                me->move("/d/jinghai/wm9");
                return 1;       
        }

        if ( arg =="fyg")
        {
                me->move("/d/feiyu/yu21");
                return 1; 
        }

        if ( arg =="pyz")
        {
                me->move("/d/paiyun/door");
                return 1; 
        }

        if ( arg =="dtf")
        {
                me->move("/d/datong/shizilukou");
                return 1; 
        }

        if ( arg =="hfz")
        {
                me->move("/d/heifeng/cross");
                return 1; 
        }

        if ( arg =="tsz")
        {
                me->move("/d/tianshui/cross");
                return 1;
        }

        if ( arg =="hsp")
        {
                me->move("/d/huashan_zx/yingbi");
                return 1;
        }

        if ( arg =="hyc")
        {
                me->move("/d/huayin/xiaolu1");
                return 1;
        }

        if ( arg =="zxg")
        {
                me->move("/d/huashan_zx/yingbi");
                return 1;
        }

        if ( arg =="wcz")
        {
                me->move("/d/wenchuan/zhenkou");
                return 1;
        }

        if ( arg =="sls")
        {
                me->move("/d/shaolin/f_square");
                return 1;
        }

        if ( arg =="kff")
        {
                me->move("/d/kaifeng/kai74");
                return 1;
        }       

        if ( arg =="mfs")
        {
                me->move("/d/mafeng/fengd9");
                return 1;
        }

        if ( arg =="kaz")
        {
                me->move("/d/path3/k_s9");
                return 1;
        }

        if ( arg =="nts")
        {
                return notify_fail("����·��û���趨��\n");
        }

        if ( arg =="hzc")
        {
                me->move("/d/hangzhou/cross");
                return 1;
        }

        if ( arg =="cd")
        {
                me->move("/d/chengdu/shizi1");
                return 1;
        }

        if ( arg =="tm")
        {
                me->move("/d/tangmen/fyuan");
                return 1;
        }

        if ( arg =="xtz")
        {
                me->move("/d/xueting/guangchang");
                return 1;
        }

        if ( arg =="txz")
        {
                me->move("/d/taxue/dating");
                return 1;
        }
        else return notify_fail("��Ҫȥ�ĵط����ڵ�ͼ֮�ϡ�\n");
}
