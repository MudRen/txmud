// Room: /d/path5/kch23.c

inherit ROOM;

void create()
{
	set("short", "ƽ��");
	set("long", @LONG
������ǰ�ɽ�Ѽ���һ��ƽ�أ��Ա�����һ���ɽʯ������
ȥ����ʮ�ֹ⻬�����Ǿ�����·���ڴ���Ϣ������һ�����֣���
ɭɭ�Ŀ���ȥ��֪���������ʲôΣ�յĶ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch22",
  "westup" : __DIR__"kch24",
  "east" :   __DIR__"milin",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
