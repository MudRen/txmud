// wood_table.c

inherit ITEM;

void create()
{
        set_name("��ľ��", ({ "wood table" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("position", "on");
                set("prep", "on");
                set("unit", "��");
                set("long", "һ�Ŵ�ľ�����㹻��ʮ����ͬʱ�Է���\n");
                set("value", 1);
        }
}

int is_container() { return 1; }
