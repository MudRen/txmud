#include <armor.h>

inherit WAIST;

void init()
{
        add_action("do_remove", "remove");
}

void create()
{
        set_name("��������", ({ "bu dai_2" }));
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
                set("base_weight", 200);
                set("wear_msg", "$N����������������󣬻��˻�����\n");
                set("armor_prop/armor", 10);
                set("no_drop", "�㲢����Ѵ�����ݵĲ������¡�\n");
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
        || obj->query("id") != "bu dai_2" || userp(obj) )
                return 0;
        tell_object(me, "�㲢����Ѵ�����ݵĲ�����ȥ��\n");
        return 1;
}
