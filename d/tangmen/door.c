// Room: /d/tangmen/door.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ��ׯ���ߴ�ʯ�ţ����ڲ�ͬ���������Ը�����һ��
��ʯ��̵��Ի������ϻ��в��ٵ�С�ף�Ҳ��֪������ʲô�õģ�
�ŵ����Ϸ���ǽ��Ƕ��һ��ʯ�壬ʯ���Ͽ��š��Ƽұ���������
���Ĵ��֣�ԭ�����������������ʿ��ɫ���������š�
LONG
	);
	set("exits", ([
  "north" : __DIR__"bridge1",
  "east" : __DIR__"lcd07",
]));

	set("outdoors", "tangmen");

	setup();
	replace_program(ROOM);
}
