// shulin1.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ��������
�졣ż������һ������Х���ص���ɽ���У�ʹ�㲻���ӿ��˽Ų���
LONG);
	set("outdoors", "taxue");

	set("exits",([
             "north" : __DIR__"shulin4",
             "east"  : __DIR__"shulin2",
             "southeast" : __DIR__"shulin",
	]));

	setup();
	replace_program(ROOM);
}
