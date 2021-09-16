// sleep.c
// Modified by Find.

void wakeup(object);

int main(object me, string arg)
{
	int rnd;
	mapping fam;
	object where = environment(me);
	mixed rtn;

	seteuid(getuid());

	if( where->query("no_sleep_room")
	|| where->query("GATE_ROOM") )
		return notify_fail("���ﲻ������˯�ĵط���\n");

	if( !(fam = me->query("family")) || (fam["family_name"] != "ؤ��") )
	{
		rtn = where->query("sleep_room", 1);

		if( (functionp(rtn) && !evaluate(rtn, me)) || !rtn )
			return notify_fail("���ﲻ������˯�ĵط���\n");
	}

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if( me->is_fighting() )
		return notify_fail("�����ںͱ��˴���أ�\n");
        
	if(where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("��С���������$N���: �����ﵱ��������! �ȵ�һ¥��Ǯ������˯!\n",me);
		return 1;
	}

	if( (me->query_temp("newlogin")
	|| ((time() - me->query_temp("sleeped")) <= 30))
	&& !where->query("hotel"))
	{
		me->start_busy(1);
		return notify_fail("�����±����ۣ�����ôҲ˯���ţ���վ�������� \n");
	}

        if( me->query_temp("on_rided") )  // �ж��Ƿ���������
                return notify_fail("�������ڻ�����������������ô��Ϣѽ��\n");

	if(where->query("sleep_room"))
	{
		tell_object(me,"��������һ�ɣ���ʼ˯����\n");
		tell_object(me,"��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
	}
	else
	{
		tell_object(me,"�������½���һ�ɣ���ʼ˯����\n");
		tell_object(me,"��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N�����½�������һ�ɣ���һ�����������������������\n",me);
	}

	if(!where->query(SAFE_ENV)) /* by Find. ���������ص� bug. */
	{
//		where->set(SAFE_ENV, 1);
		where->set_temp("changed",1);
	}
	where->add_temp("sleeping_person", 1);

	me->set("no_get", 1);
	me->set("no_get_from", 1);
	me->delete_temp("rent_paid");
	me->disable_player("<˯����>");

	rnd = random((60 - me->query_con()) / 3);
	if( rnd < 1 ) rnd = 0;
	call_out("wakeup", rnd + 10, me);

	return 1;
}

private void wakeup(object me)
{
	object where;

	if( !me || !(where = environment(me)) )
		return;

	/* �����ʣ��޷�ͨ��˯���ָ�������*/
	if((me->query("food") && me->query("water")) || !userp(me))
	{
		me->set("gin",me->query("eff_gin"));
		me->set("sen",me->query("eff_sen"));
		me->set("kee",me->query("eff_kee"));
		me->add("force", me->query("max_force")/2 - me->query("force")/2 );
	}

	me->enable_player();
	me->set_temp("block_msg/all", 0);

	if(!me->query("food"))
	{
		tell_object(me,"����Ӷ���ߴ�������ҽУ�û�취������������\n");
		tell_room(where,me->name()+"�������۾�����������\n",({me}));
		return;
	}

	if(!me->query("water"))
	{
		tell_object(me,"��ʵĿڸ����û�취������������\n");
		tell_room(where,me->name()+"�������۾�����������\n",({me}));
		return;
	}

	if(!where->query("hotel"))
		me->set_temp("sleeped",time());

	tell_room(where,me->name()+"һ����������������ػ��һ�½�ǡ�\n",({me}));

	tell_object(me,"��һ��������ֻ���������档�ûһ���ˡ�\n");


	if(where->query_temp("changed"))
	{
//		where->delete(SAFE_ENV);
		where->delete_temp("changed");
	}

	where->add_temp("sleeping_person", -1);
	me->delete("no_get");
	me->delete("no_get_from");
	if(!userp(me))
		me->have_wake_up();
}
