// Room: /d/fengtian/zhengbing.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ڷ����ǳ�͢���Ż������Գ�͢����������������������
����İ���Ҳ�����䣬������������Ҳ���Ǻ��ѣ������������
�����������Ǿ��ӵ�һԱ�ˣ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wy1",
]));

	setup();
	replace_program(ROOM);
}
