// Room: /u/w/wangs/b/kai74.c

inherit ROOM;

void create()
{
	set("short", "���Ĺ㳡");
	set("long", @LONG
���⸮�Ĺ㳡�����ίʵ׳�۷ǳ�����Բ�����ɵĿյ�ȫ��
����һ����Ӳ�Ļ������̾ͣ��㳡�������������Χ���һ��
Բ�ͼ�̳��һֻ�ɰѸߵ���ͭ�޶��������ϣ�ʹ�ÿտ��Ĺ㳡��
��ɭ�ϣ�����̾Ϊ��ֹ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai95",
  "north" : __DIR__"kai75",
  "west" : __DIR__"kai71",
  "east" : __DIR__"kai137",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
