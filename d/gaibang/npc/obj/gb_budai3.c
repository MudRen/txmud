#include <ansi.h>
#include <armor.h>
//inherit COMBINED_ITEM;
//inherit F_EQUIP;
inherit WAIST;
 
void init()
{
        add_action("do_drop", "drop");
        add_action("do_remove", "remove");
}

void create()
{
        set_name("��������", ({ "bu dai", "dai", "bag" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", 
"һֻ�ô��鲼֯�ɵĴ��ӣ��������������Ķ��٣���ؤ����ӽ�����λ�ı�־��\n");
                set("material", "waist");
                set("unit", "��");
                set("base_value", 0);
                set("base_unit", "��");
                set("base_weight", 100);                 
//              set("remove_msg", "$N����������������\n");
//              set("wear_msg", "$N��������������\n");
                set("armor_prop/armor", 1);
                set("no_drop", "ؤ����ӣ��������ڣ������������㲻�ܳ��²�����\n");
                set("no_get",1);
                set("no_give",1);
        }
        set_max_encumbrance(300);
        setup();
}

int do_drop(string str)
{
        object me,obj;
        me = this_player();

        if ( !str ) return 0;
        if ( !objectp(obj = present(str, me))  
        || obj->query("name") != "��������" || userp(obj) ) 
                return 0;
        tell_object(me,"��Ϊؤ����ӣ��������ڣ�����������\n");
        return 1;
}

int do_remove(string str)
{
        object me,obj;
        me = this_player();

        if ( !str ) return 0;
        if ( !objectp(obj = present(str, me))    
        || obj->query("name") != "��������" || userp(obj) )
                return 0;
        tell_object(me,"������ؤ��������ݵ��������㲻�ܰ������£�\n");
        return 1;
}