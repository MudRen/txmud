// /d/hangzhou/tearoom.c

inherit ROOM;

void create()
{
        set("short", "��ׯ");
        set("long", @LONG
��ׯ������Ϊ���£��������ɵĲ輸���������һ�׾�����
��ߣ���ͯ����С�ĵ�Ϊ�ݽǵĲ軨��ˮ��������������������
���������㡣
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changanw2",
]));

	set("objects",([
	__DIR__"npc/tea_boss" : 1,
]));

        setup();
        replace_program(ROOM);
}

