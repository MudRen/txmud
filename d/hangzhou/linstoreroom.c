// Room: /d/hangzhou/linstoreroom.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������Ա��ҵ������ң�ǽ��ȫ�ɴ��Ļ������ڳɣ���
���쳣�����������û��ʲôֵǮ�Ķ�����ȫ��һЩ��ʳ������
֮��Ķ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"linpath1",
]));

	setup();
	replace_program(ROOM);
}
