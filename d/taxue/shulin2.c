// shulin2.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
������ï�ܵ�ɭ�֡����ܶ���������ĳ��ݣ�һ����ɭ�ֲ���
���ա�Զ����ʱ����Ұ�޵ĺ��У��ص���ɽ���и���һ�ֲֿ��ĸ�
������ʵ�ڲ��������������
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "north" : __DIR__"shulin5",
             "west"  : __DIR__"shulin1",
             "east"  : __DIR__"shulin3",
	]));

	setup();
	replace_program(ROOM);
}
