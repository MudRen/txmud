// tr_basic.c : an basic treasure
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

#ifndef F_TREASURE
#define F_TREASURE              __DIR__"treasure"
#endif

inherit F_SAVE;
inherit F_AUTOLOAD;

inherit F_TREASURE;

// �и�bug�������������autoload�Ļ���quit֮�������������������
//                      �����¡��Ĵ�������ϵͳ�����й�������Ĵ��룬
//                      ���û�У���ôֻ����player����setһ��mapping
//                      �´�login��ʱ�����mapping��ԭ��Ʒ(�������˷�memory)
//
//              bug ���������

void create()
{
        set_name("����",({"sword"}));

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
        init_sword(10);
        setup();

}

void init()
{
        
        tr_add_action();  // �ṩ������action
    add_action("do_wield","wield"); 
        add_action("do_unwield","unwield");
}

// �ָ���Ʒ������
string query_autoload() 
{ 
        string str;

        str=this_object()->query("tr_info/file");
        if ( !stringp(str) )
                return 0;
        return str; 
}

void autoload(string param)
{
        if( stringp(param) )
                restore_object(param);
}

string query_save_file()
{
        if (!stringp(query("tr_info/file")))
                return 0;
        return query("tr_info/file");
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
        //mapping lim;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if (!ob->query("tr_info")) return 0;
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

int do_unwield(string str)
{  
        object ob;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if (!ob->query("tr_info")) return 0;

        if ( ob->query("tr_info/apply") )       // ж����������
     {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                        ob->set_heart_beat(0);
     }
} 

/*
int do_wear(string str)
{ 
        int flag, i=0;
        string tg, tp;
    object me=this_player(), ob;
        //mapping lim;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if (!ob->query("tr_info")) return 0;

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
                if ( !ob->query("tr_info/apply") )      // װ������������
                {
                        tr_apply_gift(ob, 1);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(1);
                } 
                //return 0;
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

        if (!ob->query("tr_info")) return 0;

        if ( ob->query("tr_info/apply") )       // ж����������
     {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                        ob->set_heart_beat(0);
     }
} 
*/

int do_drop(string str)
{  
        object ob;

        if (!str) return 0;
        if (str) str = lower_case(str);
        if ( !(ob = present(str, this_player())) &&
                 str!="all" )  return 0;

        if (str=="all") ob=this_object();

        if (!ob->query("tr_info")) return 0;

        if ( ob->query("tr_info/apply") ) // ж����������
                {
                        tr_apply_gift(ob, 0);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(0);
                }
}    

varargs int move(mixed dest, int silent)
{
        //int i;
        object ob, env, last_env;
        
        ob=this_object();
        last_env=environment();

        if (!ob->query("tr_info"))
                return ::move(dest, silent);

        if ( ::move(dest, silent) && objectp(ob) )
        {
                env=environment();
                // ж��ǰһ��player����������
                if (last_env && objectp(last_env) &&
                        userp(last_env) &&
                        ob->query("tr_info/apply"))
                {
                        tr_apply_gift(ob, 0);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(0);
                }
                // ���ӵ�ǰplayer������(�����charm��)
                if (env && objectp(env) &&
                        userp(env) &&
                        !ob->query("tr_info/apply") &&
                        !tr_querya(ob)["need_equip"])
                {
                        tr_apply_gift(ob, 1);
                        if (ob->query("tr_sprite") && ob->query("tr_ident")) 
                                ob->set_heart_beat(1);
                }
        }
        return 1;
}

