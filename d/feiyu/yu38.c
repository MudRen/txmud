// Room: /u/w/wangs/a/yu38.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�߽������ȣ����뿪�˰ٻ����޵ĺ�Ժ��������ȴ����
һ����ͬ�ľ��¡���������ֲ�˴�Ƭ���ɰأ������дУ���
�Ǿ��ף���������������΢�紵���µ���Ҷɳɳ���⣬����
���κ���Ϊ����������������������ͨ���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"yu39",
  "west" : __DIR__"yu37",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
