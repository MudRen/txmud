#include <armor.h>

inherit WAIST;

void init()
{
        add_action("do_remove", "remove");
}

void create()
{
        set_name("һ������", ({ "bu dai_1" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", 
"�����ô��鲼֯�ɵĴ��ӣ��������������Ķ��٣���ؤ����ӽ�����λ�ı�־��\n"
                );
                set("material", "waist");
                set("unit", "��");
                set("base_value", 0);
                set("base_unit", "��");
                set("base_weight", 100);
                set("wear_msg", "$N��һ�������������󣬻��˻�����\n");
                set("armor_prop/armor", 5);
                set("no_drop", "�㲢����Ѵ������ݵĲ������¡�\n");
                set("no_get", "���޷���������������\n");
        }         
        setup();
}

int do_remove(string arg)
{
        object me,obj;
        me = this_player();

        if ( !arg ) return 0;
        if ( !objectp(obj = present(arg, me))    
        || obj->query("id") != "bu dai_1" || userp(obj) )
                return 0;
        tell_object(me, "�㲢����Ѵ������ݵĲ�����ȥ��\n");
        return 1;
}