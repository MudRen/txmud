// zhubao_room  �鱦��

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���ٹ�����");
        set("long", @LONG
������һ�Һ��������鱦�꣬һ��������㿴��һ���ܴ��
�����ͱ�ͼ���ıߵĹ�̨�ܴ�ܸɾ�����̨��Ļ����ϰڷ��Ÿ�
�ֹ����鱦���ֻ����Σ���������мң��ᷢ�����ﲻ���ǳ���
�Ĵ��ֺŵ��鱦�꣬���������ϡ�е���䱦ʯ�����кܶ�ǰ��
�������ֻ�������ɹ��鱦���涼Ҫ�������һλ�ֺ�����
�ϰ���΢Ц�ؿ����㣬�ƺ�������ô����ڴ��������׬���֡�
�������򶫳��ű�����̩·�ˡ�
LONG
        );
        
        set("night_long",@LONG
������Ǿ��������ĵ��ٹ����У���������Ϣʱ�䣬���ﾲ
���ĵģ���ֵ����ƹ��ȴ�����ڹ�̨�󣬲�ʱ��������������
�����ڵ�ʲô�ˡ�
LONG
);
	set("exits", ([
                "east"            : __DIR__"wroad2", ]) );
	set("objects",([
		__DIR__"npc/zhubao_boss" : 1,
	]));
        setup();
}


void open_close_door(string msg,object user)
{
	object ob = present("liu qianhong",this_object());

	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"���ƹ�վ����ߺ�һ��:����ǣ�ж�塢�ڻ�������Ӫҵ�ˣ���\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"���ƹ񿴿��������˵��������ǣ��ջ����ϰ壬�����ˣ���\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"�����ˡ�\n"NOR);
		return;
	}
}