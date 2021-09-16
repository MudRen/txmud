// tr_basic.c : an basic treasure
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

#ifndef F_TREASURE
#define F_TREASURE              __DIR__"treasure"
#endif

inherit F_TREASURE;
inherit F_AUTOLOAD;
inherit F_SAVE;

// �и�bug�������������autoload�Ļ���quit֮�������������������
//                      �����¡��Ĵ�������ϵͳ�����й�������Ĵ��룬
//                      ���û�У���ôֻ����player����setһ��mapping
//                      �´�login��ʱ�����mapping��ԭ��Ʒ(�������˷�memory)

void create()
{
        set_name("����",({"blade"}));

        set_weight(5000);

        if( clonep() )
        {
                set_default_object(__FILE__);
        }
        else {
                set("unit", "��");
                set("long", "����һ������ͨͨ�ĳ�����\n");
                set("value", 10);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_blade(10);
        setup();

}

void init()
{
        tr_add_action();
}

int query_autoload()
{
  return this_object()->query("tr_info/autoload");
}

int do_look(string str)
{
        return tr_do_look(str);
}

int do_wield(string str)
{ 
        int flag, i=0;
        string tg, tp;
    object me=this_player(), ob=this_object();

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if (tr_querya(ob)["attribute"]!="weapon") return 0;

        tg="gift_limit";

        flag=1;
        if (!ob->query(tg) || !ob->query("tr_ident")) flag=0;
        else if (ob->query("pretend_gift")) flag=0;
        else if (ob->query("pretend_limit"))
                while ( ob->query(tg+"/"+sprintf("%d", i)) )
                {
                        tp=ob->query(tg+"/"+sprintf("%d", i));
                        if (!tr_on_limit(me, tp)) 
                        {
                                flag=0;
                                break;
                        }
                        i++;
                }
        if (!flag)
        {
                tell_object(me, "��Ŀǰ������װ�������Ʒ��\n");
                return 1;
        }
        else
        {
                if ( !ob->query("equipped") ) // װ������������
                {
                        tr_apply_gift(ob, 1);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(1);
                } 
        }
}

int do_wear(string str)
{ 
        int flag, i=0;
        string tg, tp;
    object me=this_player(), ob;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if (tr_querya(ob)["attribute"]!="armor") return 0;

        tg="gift_limit";

        flag=1;
        if (!ob->query(tg) || !ob->query("tr_ident")) flag=0;
        else if (ob->query("pretend_gift")) flag=0;
        else if (ob->query("pretend_limit"))
                while ( ob->query(tg+"/"+sprintf("%d", i)) )
                {
                        tp=ob->query(tg+"/"+sprintf("%d", i));
                        if (!tr_on_limit(me, tp)) 
                        {
                                flag=0;
                                break;
                        }
                        i++;
                }
        if (!flag)
        {
                tell_object(me, "��Ŀǰ�����ܴ��������Ʒ��\n");
                return 1;
        }
        else
        {
                if ( !ob->query("tr_info/is_apply") )   // װ������������
                {
                        tr_apply_gift(ob, 1);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(1);
                } 
                //return 0;
        }
}

int do_unwield(string str)
{  
        object ob;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if ( ob->query("tr_info/is_apply") )    // ж����������
     {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                        ob->set_heart_beat(0);
     }
} 

int do_remove(string str)
{  
        object ob;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if ( ob->query("tr_info/is_apply") )    // ж����������
     {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                        ob->set_heart_beat(0);
     }
} 

int do_drop(string str)
{  
        object ob;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if ( ob->query("tr_info/is_apply") ) // ж����������
                {
                        tr_apply_gift(ob, 0);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(0);
                }
}    

varargs int move(mixed dest, int silent)
{
        object ob, env, last_env;
        
        ob=this_object();
        last_env=environment();

        if ( ::move(dest, silent) && objectp(ob))
        {
                env=environment();
                // ж��ǰһ��player����������
                if (last_env && objectp(last_env) &&
                        userp(last_env) &&
                        ob->query("tr_info/is_apply"))
                {
                        tr_apply_gift(ob, 0);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(0);
                }
                // ���ӵ�ǰplayer������(�����charm��)
                if (env && objectp(env) &&
                        userp(env) &&
                        !ob->query("tr_info/is_apply") &&
                        !tr_querya(ob)["need_equip"])
                {
                        tr_apply_gift(ob, 1);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(1);
                }
        }
        return 1;
}

int do_recognize(string str)
{  
        int i;
        object ob;
        object me=this_player();

        if (!str) 
        {
                write(@HELP

ָ���ʽ : 
    1. recg/jianding xxx
    2. recgsure/jdsure xxx
    3. recglike/recglove/recgwant xxx
       jdlike/jdlove/jdwant xxx


��ָ����԰�����ʶ��δ��������Ʒ��
HELP
                );
                return 1;
        }

        if (str) str = lower_case(str);
        if ( !ob = present(str, me) ) return notify_fail("��Ҫ����ʲô��\n");

        if (ob->query("tr_ident")) 
                return notify_fail("����Ʒ�Ѿ���������\n");

        i=ob->query("tr_info/is_apply");
        if (i)  // ж����������
    {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(0);
    }

        // ����Ҫ�弸�仰���йؼ���skill�����ơ������ɹ��ʵ�
        // ���������ֵ����һ���������� "��Ʒ" ��ʾ

        tr_revert(ob);

        if (i)
    {
                tr_apply_gift(ob, 1);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(1);
    }

        tell_object(me, "������ɣ�\n\n");
   //me->improve_skill( "recognize", 
//         me->query_skill("literate",1)+random(me->query_skill("literate",1)) );

        return tr_do_look(str);
} 

