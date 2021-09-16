// action.c
// Modified by Find.

static mixed busy, interrupt;
static int perform_busy;

nomask void start_perform_busy(int n)
{
	if(!intp(n))
		return;

	if(perform_busy)
		perform_busy += n;
	else
		perform_busy = n;
}

nomask void continue_perform_busy()
{
	if(perform_busy < 0)
		perform_busy = 0;
	else if(perform_busy > 0)
		--perform_busy;
}

nomask int is_perform_busy()
{
	return perform_busy > 0;
}

nomask varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	if( !new_busy )
		return;
	if( !intp(new_busy) && !functionp(new_busy) )
		error("action: Invalid busy action type.\n");
	if(intp(new_busy) && intp(busy))
		busy += new_busy;
	busy = new_busy;
	if( !intp(new_interrupt) && !functionp(new_interrupt) )
		error("action: Invalid busy action interrupt handler type.\n");
	interrupt = new_interrupt;
	set_heart_beat(1);
}

nomask mixed query_busy() { return busy; }
nomask int is_busy() { return busy!=0; }
nomask void stop_busy() { busy = 0; }

// This is called by heart_beat() instead of attack() when a ppl is busy
// doing something else.
void continue_action()
{
	if( intp(busy) && (busy > 0) )
	{
		busy--;
		return;
	}

	else if( functionp(busy) )
	{
		if( !evaluate(busy, this_object()) )
		{
			busy = 0;
			interrupt = 0;
		}
	}

	else
	{
		busy = 0;
		interrupt = 0;
	}
}

nomask void interrupt_me(object who, string how)
{
	if( !busy ) return;

	if( intp(busy) && intp(interrupt) )
	{
		if( busy < interrupt )
			busy = 0;
	}

	else if( functionp(interrupt) )
	{
		if( evaluate(interrupt, this_object(), who, how) )
		{
			busy = 0;
			interrupt = 0;
		}
	}
}

// This function is for temporary conditions's recovery call_outs, bcz
// such recovery function call_out might be destroyed if some wizard
// destructed the object that is reponsible of it, so we let users launch
// the call_out themself. Thus we can make sure the recovery call_out.
// 
// Because this could cause a serious security problem, so we need highest
// security check here.
nomask int start_call_out(function fun, int delay)
{
	if( !previous_object()
	||  (geteuid(previous_object()) != ROOT_UID
	     && userp(this_object())
	     && this_player(1) != this_object()))
		return 0;

	call_out("eval_function", delay, fun);
	return 1;
}

nomask void eval_function(function fun) { evaluate(fun); }