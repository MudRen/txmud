// Room: /d/path5/kch16.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ɽ�乵������ʯ���أ�Ȫˮ��϶�������ḧ��Щ����
С�������ߵ�����·���������һ�����硣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"kch17",
  "northup" : __DIR__"kch15",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
