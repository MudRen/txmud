// desk.c

inherit ITEM;

void create()
{
        set_name("����", ({ "desk"}) );

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
����ǲ��õ������������������ӵ���ѹ��һ�ݡ�������˵������
���ϰ���һЩֽ���ֵ�֮��Ļ����þߣ�����һ����������
LONG
                );
                set("value", 1);
        }
}

int is_container()
{
        return 1;
}

