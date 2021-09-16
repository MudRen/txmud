// Room: /d/fengtian/wy1.c

inherit ROOM;

void create()
{
	set("short", "��Զ·");
	set("long", @LONG
��Զ·��һ��������Ĵ�֣�Ҳ�Ƿ������ɵ�����ֶ�����
ͨ���ֵ�Ҳ�൱���������������±Ƚ�̫ƽ�������β��õķ���
���������˰Ѿ�·�����ˣ����������Ϲٵ��ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zhengbing",
  "west" : __DIR__"guanlu1",
  "east" : __DIR__"wy2",
  "north" : __DIR__"xiang1",
]));

	set("objects",([
		NPC_DIR"xunpu" : 3,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
