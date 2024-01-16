        flow = cal_flow(ROUGHNESS, WIDTH * guess, SLOPE, cal_hydrolic_radius(guess, WIDTH));
        printf("depth:%.1f  flow:%.1f  error:%.1f\n", guess, flow, FLOW-flow);