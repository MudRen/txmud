// table.c

inherit ITEM;

void create()
{
        set_name("��ľ��", ({ "wooden table"}) );

        set_weight(5000000);
        set_max_encumbrance(800000);

        set("no_get", 1);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("position", "on");
                set("prep", "on");
                set("unit", "��");
                set("long", @LONG
����һ�źܴ��ľ����
LONG
                );
                set("value", 1);
        }
}

int is_container()
{
        return 1;
}

