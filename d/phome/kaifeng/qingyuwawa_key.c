// key.c
// ��ҵ���������������˴�Ӧ���Զ����ġ�

inherit ITEM;
inherit F_AUTOLOAD;

int query_autoload () {return 1;}

void create()
{
        set_name("���������ڿ��⸮�ļ���Կ��", ({"home key","key"}));
        set("long",
                "����һ��ͭԿ�ף��������ھ���ʹ�ã���ĥ������������\n");
        set("unit", "��");
        set("weight", 10);
        set("value", 0);
}

//void owner_is_killed() { destruct(this_object()); }
