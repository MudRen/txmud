// Room: /u/w/wangs/a/yu17.c

inherit __DIR__"patroling";

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С���ϣ������������ɰأ��ļ����࣬����
���أ�����������������������������Ķ��������������
��ĳ��������󷹲˵�����������Ʈ�˳�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"yu19",
  "west" : __DIR__"yu18",
  "northeast" : __DIR__"yu16",
]));
       set("outdoors","feiyu");

	setup();
}
