// Room: /u/w/wangs/a/yu16.c

inherit __DIR__"patroling";

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С���ϣ������������ɰأ��ļ����࣬����
���أ�����������������������������Ķ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"yu17",
	"east" : __DIR__"yu15",
	"north" : __DIR__"chitang"
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/zhenhuimin" : 1,
]));
       set("outdoors","feiyu");

	setup();
}
