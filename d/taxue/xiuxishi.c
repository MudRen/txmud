// xiuxishi.c ��Ϣ��
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ϣ��");
        set("long",@LONG
�������е��ӵ���Ϣ�ң����������������۵�������õ�ƣ�ͻ��⣬
���ﲢ�Ű��ż��Ŵ�������ȥ�����ʵ����ӡ�������ô��ʱ�䵹��������
һ�µ�Ҳ����
LONG);

	set(SAFE_ENV,1);
	set("exits",([
		"south" : __DIR__"donglang1",
	]));

	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
