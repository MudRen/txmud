// Room: /d/fengtian/chou.c

inherit ROOM;

void create()
{
	set("short", "���ׯ");
	set("long", @LONG
�����ׯ����Ϸ�������һ���ˣ��ϰ��ɽ��ϲɹ�һЩ
�õ�˿�У��ڷ������׬����Ǯ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wy4",
]));

	setup();
	replace_program(ROOM);
}
