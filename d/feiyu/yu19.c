// Room: /u/w/wangs/a/yu19.c

inherit __DIR__"patroling";

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С���ϣ������������ɰأ��ļ����࣬����
���أ�����������������������������Ķ��������Ϸ���һ
������ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu20",
  "northeast" : __DIR__"yu17",
	"west" : __DIR__"yaofang",
]));
       set("outdoors","feiyu");

	setup();
}
