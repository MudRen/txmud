// shulin5.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
������ï�ܵ�ɭ�֡����ܶ���������ĳ��ݣ�һ����ɭ�ֲ���
���ա�Զ����ʱ����Ұ�޵ĺ��У��ص���ɽ���и���һ�ֲֿ��ĸ�
������ʵ�ڲ��������������
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "north" : __DIR__"shulin8",
             "south" : __DIR__"shulin2",
             "west"  : __DIR__"shulin4",
             "east"  : __DIR__"shulin6",
	]));

	setup();
	replace_program(ROOM);
}
