#include <armor.h>

inherit WAIST;

void init()
{
        add_action("do_remove", "remove");
}

void create()
{
        set_name("两个布袋", ({ "bu dai_2" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", 
"这是用粗麻布织成的袋子，身上所带布袋的多少，是丐帮弟子江湖地位的标志。\n"
                );
                set("material", "waist");
                set("unit", "个");
                set("base_value", 0);
                set("base_unit", "个");
                set("base_weight", 200);
                set("wear_msg", "$N将两个布袋别在身后，晃了晃腰。\n");
                set("armor_prop/armor", 10);
                set("no_drop", "你并不想把代表身份的布袋丢下。\n");
                set("no_get", "你无法将布袋拿起来。\n");
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
        tell_object(me, "你并不想把代表身份的布袋除去。\n");
        return 1;
}
