// gudi3.c
// by dicky

inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long",@long
���߽�������������ֻ��һ����С�Ķ�Ѩ��ֻ�������߰˸��ˡ����й���
������ʲô������ֻ��ģ���Ŀ�����š�����ʯ�ڵĵط���һ��ʯ���������
�ˣ�������������Ϣһ�¡�
long);

	set(SAFE_ENV,1);
	set("exits",([
		"out" : __DIR__"gudi2",
	]));

	set("sleep_room",1);
        set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
