// Room: /d/path5/e02.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������С·��������ï�ܵ����֣�ϡ�ϵĹ���������
Ҷ��ҡ��һ��һ������ϡ���Կ���·�ĺۼ������ϵ����г�����
���ֹ�ľֲ�С�Ĳ�Ҫ�����Լ�Ŷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"e03",
  "west" : __DIR__"e01",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}