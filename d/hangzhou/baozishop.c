// /d/hangzhou/baozishop.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ�����ţ�һ�������������˴�ζӭ��������ζ����Ȼ��
�������Ӻ���������֪ζ�ۣ������ڼ���µµ��������˵��Ҳ��
�޷����ܵģ���С������������ȥ���к����ˣ��������ⲻ��
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changane1",
]));

	set("objects",([
	__DIR__"npc/baozi_huoji" : 1,
]));

        setup();
        replace_program(ROOM);
}

