// Room: /d/path5/kch11.c

inherit ROOM;

void create()
{
	set("short", "���ɽ��");
	set("long", @LONG
�����ڵ�����ɽ�ֻ���Ϸ���Զ��һ�����ߵ�ɽ�������
ǰ����ɽ��ȥ���ϱ׶���ɽ�ƣ����òԲ����ȡ�һ����ɽ�紵
�����������Щ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch10",
  "southdown" : __DIR__"kch12",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
