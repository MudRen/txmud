// fly.c

#include <ansi.h>
inherit F_NATURE;

string fname = "/d/shaolin/fayanvoid";
private void do_select(string num,object me,object *rooms);
private void arrive_dest(object me,object room);

int conjure(object me)
{
	mapping where;
	int time;
        object *inv,*rooms = ({});
	string out;

	if(!objectp(me) || !environment(me) || (me->query("class") != "shaolin"))
		return 0;

	if( me->query_skill("dacheng-fofa",1) < 100)
		return notify_fail("��ġ���˷𷨡���Ϊ���㡣�޷�ʩչ�����д��󡻡�\n");

	if(me->is_fighting())
		return notify_fail("ս�����޷�ʩչ�����д��󡻡�\n");

	if(me->query("atman") < 500)
		return notify_fail("����������㡣�޷�ʩչ�����д��󡻡�\n");
        if(!environment(me)->query("outdoors"))
                return notify_fail("�˵��޷�ʩչ�����д��󡻡�\n");

        inv = filter_array(deep_inventory(me),
                (: $1->is_character() :));

        if(sizeof(inv))
                return notify_fail("��ķ���Ϊ�ܵ������˵�Ӱ�죬�޷�ʩչ�����д��󡻡�");


	if(!mapp(where = me->query("family/fofa")) || !sizeof(where))
		return notify_fail("��ġ��������ۡ�Ŀǰû���κη����޷�ʩչ�����д��󡻡�\n");

	time = time();

	foreach(string fname,int t in where)
	{
		object room;
		string f;

		if( (t - time) <= 0 )
		{
			me->delete("family/fofa/"+fname);
			continue;
		}

		f = replace_string(fname,"&","/");
		room = find_object(f);
		if(!room)
			room = load_object(f);
		if(!room)
		{
			me->delete("family/fofa/"+fname);
			continue;
		}
		else
			rooms += ({ room });
	}

	if(!sizeof(rooms))
		return notify_fail("��ġ��������ۡ�Ŀǰû���κη����޷�ʩչ�����д��󡻡�\n");

	if(sizeof(rooms) == 1)
	{
		do_select(sprintf("%d",1),me,rooms);
		return 1;
	}

	out = "��Ŀǰ���������ĵط��У�\n";
	for(int i=0;i<sizeof(rooms);i++)
		out += sprintf("%d. ��%s��\n",(i+1),rooms[i]->query("short"));

	tell_object(me,sprintf("%s\n��ѡ����Ҫǰ���ĵص�(q ȡ��)��",out));
	input_to((: do_select :),me,rooms);
	return 1;
}

private void do_select(string num,object me,object *rooms)
{
	int n, day = query_day(0),ski,up;
	object obj;
	mapping t;

	if(!objectp(me) || (num[0] == 'q'))
		return;

	if(!sscanf(num,"%d",n))
	{
		tell_object(me,"ѡ�����\n");
		return;
	}

	if( (n < 1) || (n > sizeof(rooms)) )
	{
		tell_object(me,"ѡ�����\n");
		return;
	}

	ski = me->query_skill("dacheng-fofa",1);
	if(ski < 150)
		up = 10;
	else if(ski < 200)
		up = 20;
	else
		up = 30;

	if(!mapp(t = me->query("family/flytime")))
	{
		t = allocate_mapping(2);
		t["date"] = day;
		t["times"] = 0;
	}

	if( (t["date"] == day) && (t["times"] >= up) )
	{
		tell_object(me,sprintf("������Ѿ�̫���ˣ���Ҳû�о���ʩչ�����д����ˡ�\n"));
		return;
	}
	if(!t["date"] || (t["date"] != day))
	{
		t["date"] = day;
		t["times"] = 1;
	}
	else
		t["times"]++;

	me->set("family/flytime",t);

	n--;

	me->start_busy(10);

	tell_object(me,sprintf("\n˫�۽��գ�˫�ֺ�ʮ���Ժ����������ֳ���%s���ľ���
��ֻ���Ľ���һ�ᣬ�Ѳ�֪���ںδ�������\n\n",rooms[n]->query("short")) );

	tell_room(environment(me),sprintf(BWHT BLU"%s˫�۽��գ�˫�ֺ�ʮ����ֻ������Χ�Ŀ�����ʼ������ת��
һ��ѣĿ���������%s������ǰ��ʧ�ˡ�����\n\n" NOR,me->name(),me->name()),({me}));

	me->add("atman", -500);
	me->move(fname,1);
	if(objectp(obj=me->query_temp("on_rided")))
		obj->move(fname);
	call_out((: arrive_dest :),5,me,rooms[n]);
}

private void arrive_dest(object me,object room)
{
	object obj;

	if(!objectp(me))
		return;

	tell_room(room,sprintf(BWHT BLU"\nͻȻ����ֻ������Χ�Ŀ�����ʼ������ת������
һ��ѣĿ���������%s����������ǰ������\n\n"NOR,me->name()));


	tell_object(me,sprintf("\n��֪���˶೤ʱ�䣬��о���Χ�ľ��������ķ����˱仯��
����һ�������Ѿ������ˡ�%s��������\n\n",room->query("short")));

	me->move(room);
	if(objectp(obj=me->query_temp("on_rided")))
		obj->move(room);

	if(me->query("gin") > 20)
		me->set("gin",20);
	if(me->query("kee") > 20)
		me->set("kee",20);
	if(me->query("sen") > 20)
		me->set("sen",20);

	me->stop_busy();
}
