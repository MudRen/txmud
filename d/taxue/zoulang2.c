// zoulang2.c ����2

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
����ͨ��̤ѩɽׯ���õĵ�·��������һ��Բ�εĹ��ţ����������
���˻���ʹ���������ﶼ�����ŵ����㡣�����ֺ�������͸��һ��ɱ����
�㲻�����˸����䡭��
LONG);

	set("outdoors","taxue");

	set("exits",([
		"north" : __DIR__"huazhen1",
		"southwest" : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}
