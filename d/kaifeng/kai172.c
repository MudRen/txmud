// Room: /u/w/wangs/b/kai172.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������İ��貢���Ǻܽ������������˼���Բľ����������
�������ҵķ��˼��ѳ������ӡ�һ��С���û����ɵĿ��ڹ�̨
�ߣ������������ֻ���������������˸��к��������������
���Ⲣ����ô�á�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai171",
]));
        set("objects",([
        __DIR__"npc/bboss": 1,
]));

	setup();
	replace_program(ROOM);
}
