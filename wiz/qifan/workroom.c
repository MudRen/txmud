// Room: /wiz/qifan/workroom.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG "��  ��" NOR);
        set("long",@LONG

    _________________[1;33;40m _____________ [0m_________________  
    []==[]|__[1;36;41m    [0m__|_[1;33;43m|             |[0m__|__[1;36;41m    [0m__[]==[]    
    []==[]__|[1;36;41m �� [0m_|__[1;33;43m| [32m˭ �� ˪ ʮ [33m|[0m__|__[1;36;41m �� [0m|_[]==[]  
    []==[]|__[1;36;41m �� [0m__|_[1;33;43m| [32m�� �� �� �� [33m|[0m__|__[1;36;41m ʮ [0m__[]==[]
    []==[]__|[1;36;41m �� [0m_|__[1;33;43m| [32m�� �� δ ĥ [33m|[0m__|__[1;36;41m �� [0m|_[]==[]  
    []==[]|__[1;36;41m �� [0m__|_[1;33;43m| [32mƽ ʾ �� һ [33m|[0m__|__[1;36;41m �� [0m__[]==[]
    []==[]__|[1;36;41m �� [0m_|__[1;33;43m| [32m�� �� �� �� [33m|[0m__|__[1;36;41m �� [0m|_[]==[]  
    []==[]|__[1;36;41m �� [0m__|_[1;33;43m| [32m �� �� �� ��[33m|[0m__|__[1;36;41m �� [0m__[]==[]
    []==[]__|[1;36;41m �� [0m_|__[1;33;43m|_____________[33m|[0m__|__[1;36;41m ҹ [0m__[]==[]  
    []==[]|__[1;36;41m    [0m__|__|__|__|__|__|__|___[1;36;41m    [0m__[]==[]
    []==[]__|__|__|__|__|__|__|_|__|_|__|__|___[]==[]  
    []==[]|__|__|__|__|__|__|_|__|_|__|__|__|__[]==[]
LONG
	 );

        set("exits",([
	"wiz" : "/d/wiz/wizroom",
         "cn" : "/d/changan/jiulou2",
	"tm" : "/d/tangmen/fyuan",
]));

//	set("objects",([
//          "/wiz/qifan/shinv":1,
//      ]));

	set("item_desc", ([
	"ditu" :	WHT "\n������-cac     �����-ftc     ��Ҵ�-zjc     ���µ�-myd 
    ������-wmd     ����-fyg     ����կ-pyz     ��ͬ��-dtf 
    �ڷ�կ-hfz     ��ˮ��-tsz     ��ɽ��-hsp     ������-hyc 
    ��ϼ��-zxg     �봨��-wcz     ������-sls     ���⸮-kff
    ���ɽ-mfs     ����կ-kaz     ţͷɽ-nts     ���ݳ�-hzc
    �ɶ�  -cd      ����  -tm      ѩͤ��-xtz     ̤ѩׯ-txz

             �������ȥʲô�ط�,������qu xxx �Ϳ��Ե������뵽��ĵط�!\n" NOR,
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
        object me = this_player(1);

        if(me && geteuid(me) == "qifan")
                return 0;
        else
                return 1;
}

int do_qu(string arg)
{
         object me;
         me = this_player();
         if( !arg )
         return notify_fail("����ȥʲô�ط���\n");

        if ( arg =="cac")
         {
                me->move("/d/changan/jiulou2");
                return 1;
         }
         
        if ( arg =="ftc")
         {
                me->move("/d/fengtian/jiulou");
                return 1;       
         }
        
        if ( arg =="zjc")
         {
                me->move("/d/jinghai/zhuque6");
                return 1; 
        }

        if ( arg =="myd")
         {
                me->move("/d/jinghai/moon7");
                return 1;       
        }

        if ( arg =="wmd")
         {
                me->move("/d/jinghai/wm3");
                return 1;       
        }


        if ( arg =="fyg")
         {
                me->move("/d/feiyu/yu21");
                return 1; 
        }

        if ( arg =="pyz")
         {
                me->move("/d/paiyun/lh_tang");
                return 1; 
        }

        if ( arg =="dtf")
         {
                me->move("/d/datong/minju3");
                return 1; 
        }

        if ( arg =="hfz")
         {
                me->move("/d/heifeng/maowu");
                return 1; 
        }
 
        if ( arg =="tsz")
         {
                me->move("/d/tianshui/cross");
                return 1;
        }

        if ( arg =="hsp")
         {
                me->move("/d/huashan_zx/guange3");
                return 1;
        }

        if ( arg =="hyc")
         {
                me->move("/d/huayin/daguchang");
                return 1;
        }

        if ( arg =="zxg")
         {
                me->move("/d/huashan_zx/yingbi");
                 return 1;
        }

        if ( arg =="wcz")
         {
                me->move("/d/wenchuan/fulai");
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
                me->move("/d/changan/jiulou3");
                 return 1;
        }

        if ( arg =="nts")
         {
                me->move("/d/changan/jiulou3");
                 return 1;
        }
        
        if ( arg =="hzc")
         {
                me->move("/d/hangzhou/hotel");
                 return 1;
        }

        if ( arg =="cd")
         {
                me->move("/d/chengdu/furuilou");
                 return 1;
        }

        if ( arg =="tm")
         {
                me->move("/d/tangmen/fyuan");
                 return 1;
        }

        if ( arg =="xtz")
         {
                me->move("/d/changan/jiulou2");
                 return 1;
        }

        if ( arg =="txz")
         {
                me->move("/d/changan/jiulou2/");
                 return 1;
        }
		return 0;
}
