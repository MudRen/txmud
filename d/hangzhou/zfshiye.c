// Room: /d/hangzhou/zfshiye.c

inherit ROOM;

void create()
{
	set("short", "ʦү��");
	set("long", @LONG
���Ǳ�����ʦү�ķ��䣬��ʦү�����������ϣ�Ϊ�˾�ϸ��
������֪�����˲������顣��ʦү�ķ���������Ǽ򵥣�������
���ϰڵ��������鼮��������עĿ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zfpath5",
]));

	setup();
	replace_program(ROOM);
}
