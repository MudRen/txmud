// Room: /u/w/wangs/b/kai162.c

inherit ROOM;

void create()
{
	set("short", "·��");
	set("long", @LONG
�����ֵľ�ͷ��һ�����ɸߵ�����ϣ���������յ����ĵ�
����ÿ��ĺɫ���٣�����ƻ�ͨ��������Ժ���д���һƬ��Ц֮
�����м��ּ��Ų�ö��������־ƣ��������ϸ账����һƬ��
ƽ���󡣺��ɽ־������Ķ�������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"kai161",
  "west" : __DIR__"kai163",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
