//tianma.c

inherit ITEM;

void create()
{
        set_name("天麻", ({ "tian ma"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的天麻,天麻的性味甘辛微温,用于平肝熄火，定精止痛。\n");
        }
}
