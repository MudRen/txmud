// shulin.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
���Ǻ�ɽ��һƬï�ܵ������У����ܾ����ĵġ���ɭɭ��ʮ�����ˣ�
һ��紵�����㲻��һ����
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "northwest" : __DIR__"shulin1",
             "northeast" : __DIR__"shulin3",
             "south" : __DIR__"xiaolu",
	]));

	setup();
	replace_program(ROOM);

}
