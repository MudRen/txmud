// obj: /wiz/zling/fly.c

#include <ansi.h>
inherit ITEM;

void create()
{
       set_name(HIG "ħ����" NOR, ({"magic door","md"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                WHT "\n������-cac     �����-ftc     ��Ҵ�-zjc     ���µ�-myd 
������-wmd     ����-fyg     ����կ-pyz     ��ͬ��-dtf 
�ڷ�կ-hfz     ��ˮ��-tsz     ��ɽ��-hsp     ������-hyc 
��ϼ��-zxg     �봨��-wcz     ������-sls     ���⸮-kff
���ɽ-mfs     ����կ-kaz     ţͷɽ-nts     ���ݳ�-hzc
�ɶ�  -cd      ����  -tm
�������ȥʲô�ط�,������qu xxx �Ϳ��Ե������뵽��ĵط�!
 \n");
                set("value", 5);
                     set("no_drop",1);
                set("unit", "��");
        }
}


void init()
{
        add_action("do_qu","qu");
}


int do_qu(string arg)
{
         object me;
         me = this_player();
         if( !arg )
         return notify_fail("����ȥʲô�ط���\n");

    if ( arg =="cac")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˳�����\n" NOR,me);
                me->move("/d/changan/jiulou2");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1;
         }
         
        if ( arg =="ftc")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˷��졣\n" NOR,me);
                me->move("/d/fengtian/jiulou");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1;       
         }
        
        if ( arg =="zjc")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ����Ҵ塣\n" NOR,me);
                me->move("/d/jinghai/zhuque6");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1; 

        }

        if ( arg =="myd")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�����µ���\n" NOR,me);
                me->move("/d/jinghai/moon7");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1;       
        }

        if ( arg =="wmd")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ����������\n" NOR,me);
                me->move("/d/jinghai/wm3");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1;       
        }

        if ( arg =="fyg")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ������\n" NOR,me);
                me->move("/d/feiyu/yu21");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1; 
        }

        if ( arg =="pyz")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ������կ��\n" NOR,me);
                me->move("/d/paiyun/lh_tang");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1; 
        }

        if ( arg =="dtf")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˴�ͬ����\n" NOR,me);
                me->move("/d/datong/minju3");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1; 
        }

        if ( arg =="hfz")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˺ڷ�կ��\n" NOR,me);
                me->move("/d/heifeng/maowu");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                return 1; 
        }
 
        if ( arg =="tsz")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ����ˮ��\n" NOR,me);
                me->move("/d/tianshui/cross");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="hsp")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˻�ɽ��\n" NOR,me);
                me->move("/d/huashan_zx/guange3");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="hyc")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˻����塣\n" NOR,me);
                me->move("/d/huayin/daguchang");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="zxg")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ����ϼ����\n" NOR,me);
                me->move("/d/huashan_zx/yingbi");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="wcz")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ���봨��\n" NOR,me);
                me->move("/d/wenchuan/fulai");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="sls")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�������¡�\n" NOR,me);
                me->move("/d/shaolin/f_square");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="kff")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˿��⡣\n" NOR,me);
                me->move("/d/kaifeng/kai74");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }       

        if ( arg =="mfs")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�����ɽ��\n" NOR,me);
                me->move("/d/mafeng/fengd9");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="kaz")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˿���կ��\n" NOR,me);
                me->move("/d/changan/jiulou3");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="nts")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ��ţͷɽ��\n" NOR,me);
                me->move("/d/changan/jiulou3");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }
        
        if ( arg =="hzc")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˺��ݡ�\n" NOR,me);
                me->move("/d/hangzhou/hotel");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="cd")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�˳ɶ���\n" NOR,me);
                me->move("/d/chengdu/furuilou");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }

        if ( arg =="tm")
         {
                message_vision(HIG "\nֻ��$N��һ��ħ���ţ�˲��ȥ�����š�\n" NOR,me);
                me->move("/d/tangmen/fyuan");
                message_vision(HIG "\n����ͻȻ����һ���ѷ�$N���������˳���\n" NOR,me);
                 return 1;
        }
        return 0;
}

