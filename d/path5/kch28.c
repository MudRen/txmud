// Room: /d/path5/kch28.c

inherit ROOM;

void create()
{
	set("short", "�±�");
	set("long", @LONG
���ߵ����ֻ��һ�����յ��±ڼ�����ɽ·���ұߣ�����
��������Ԩ�������±ڿ�ȥ����Ȼ�е�һ��ѣ�Σ��ƺ��±�����
ʲô�����ڶ���һ����ϸ�Ĵ�ʯ��մ��򶫱ߵ��ͱڣ�û�а���
��Ҫ����Ŷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kch29",
  "westdown" : __DIR__"kch27",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
