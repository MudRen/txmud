// Room: /d/path5/kch19.c

inherit ROOM;

void create()
{
	set("short", "���ɽ��");
	set("long", @LONG
�������������ɽ�Ľ��£����ѵ�ɽ·�߳������С��С�ݡ�
���ۿ�ȥ��ֻ��һ����ɫ�Ĳ��˴���˷����㱻����Ȼ��������
���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"kch20",
  "west" : __DIR__"kch18",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
