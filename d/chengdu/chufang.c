// Room: /d/changan/chufang.c

inherit ROOM;

void create()
{
	set("short", "��ܽ��¥���");
	set("long", @LONG
��������ܽ��¥�ĺ���������������޴��ˮ�ױ�����һ��
��ľ�������ֵļ����϶������ù���������ӡ��ſڹ���һ��ľ
����(pai)��
LONG
);

        set("no_fight",1);
	set("exits",([
	"east" : __DIR__"furuilou",
]));
	set("item_desc",([
                "pai" : "����ϴ(xi)���ӡ�ϴ���С����\n",
]));

	set("objects",([
		__DIR__"npc/cooker" : 1,
]));

	setup();
	replace_program(ROOM);
}
